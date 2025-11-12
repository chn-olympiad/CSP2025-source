#include <bits/stdc++.h>
#define int long long
using namespace std;
int pow2[25]={0,1,2,4,8,116,32,64,128,
256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288};
//pow2 是2的n次方 
//500000 < 2^19
//是不是有异或的数学函数可以直接用啊
//但是我不会用，只能自己写一个了 awa
//我服了 只想出暴力解法 最多拿60 
//10：12：49 2025-11-01 
//好吧好像有点问题
//第5个样例错了
//11：00：37 
struct Node{
	int num;
	bool v=0;
}a[500005];
int n,k,ans;
int xorr(int a,int b){
	string s1,s2;//字符串存储2进制 
	for(int i=20;i>=1;i--){//最大2^20 
		if(a>=pow2[i]) {//如果可以达到位数大小 
			s1+='1';//增加一位 
			a-=pow2[i];//减去 
		}
		else {
			s1+='0';//如果不可以则加0占位 
		} 
		//b也是同样操作 
		if(b>=pow2[i]) {//如果可以达到位数大小 
			s2+='1';//增加一位 
			b-=pow2[i];//减去 
		}
		else {
			s2+='0';//如果不可以则加0占位 
		} 
	}
//	cout<<s1<<endl<<s2<<endl;
	for(int i=1;i<=20;i++){
		if(s1[i]!=s2[i]) s2[i]='1';
		else s2[i]='0';
//		cout<<s1<<endl<<s2<<endl;
	}
	int ans=0;
//	cout<<s2<<endl;
	for(int i=20;i>=1;i--){
		if(s2[i]=='1') {
			ans+=pow(2.0,(i-18)*1.0);
//			cout<<"i is"<<i<<endl;
		}
//		cout<<ans<<endl;
	}
	return ans;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].num);
		if(a[i].num==k){//如果自己本身就可以 
			ans++;//答案增加 
			a[i].v=1;//标记为已访问 
		}
	}
	int t;
	for(int i=1;i<=n;i++){
		if(a[i].v==1||a[i+1].v==1) continue;//如果已访问则跳过 
		t=xorr(a[i].num,a[i+1].num);//t初始为ai与ai+1的异或 
		a[i].v=1;//标记访问 
		for(int j=i+1;j<=n;j++){
			if(t==k){//如果答案可以 
				ans++;//数量增加 
				i=j; 
				break;//退出 
			}
			if(a[j].v==1) break;//若已被访问退出区间 
			t=xorr(t,a[j].num);//t为aj与t的异或 
			//t此时为aj至ai之间的区间异或和 
			a[j].v=1;//标记访问 
			
		}
	} 
	printf("%d",ans);
	
	
	return 0;
} 
