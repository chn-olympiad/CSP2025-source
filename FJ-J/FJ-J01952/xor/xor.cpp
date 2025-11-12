#include<bits/stdc++.h> 
using namespace std;
long long n,k,ans;
long long f,sec=1,se,f1=1,newsum,sum1,se1;//辅助 
long long s[500010];//序列 
bool b[500010];//防止重叠 
void dfs(int st,int en,long long sum){//st:开始位置，en:结束位置，sum:值
se=0;
newsum=0;
if(b[en]==true) return;
if(en>n) return;
if(sum==k){
	ans++;
	return;
}
b[st]=true;
b[en]=true; 
for(int i=1;i<=20;i++){
		sec=sec*2;//sec值最大化 
	} 
	if(st==en){
		f=s[st];
		while(f!=0){
			se*=10;//二进制 
			if(f>=sec){//算 
				f=f-sec;
				se+=1;
			}
			sec=sec/2; 
		}
		sum=se; 
	}else{
		f=s[en];//算异或 
		while(f!=0){
			se*=10;
			if(f>=sec){ 
				f=f-sec;
				se+=1;
			}
			sec=sec/2; 
		}
		for(int i=1;i<=7;i++){//拆位 
			sum1=(sum/f1)%10;//位
			se1=(se/f1)%10;//位 
			if(sum1==se1) newsum*=10;//相同
			else newsum=newsum*10+1;//不同 
		}
		sum=newsum;//得二进制 
	}
	dfs(st,en+1,sum); //往后找 
	return;
} 
int main(){
	 	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&s[i]);//入
	if(k==0){//k=0就选相同的数 
		for(int i=1;i<=n;i++){
			if(s[i]==s[i+1]){//找相同 
				ans++;
				while(s[i]==s[i+1]) i++;//跳过相同 
			}
		}
		printf("%d",ans);
		return 0; 
	}
	for(int i=1;i<=20;i++){
		sec=sec*2;//sec值最大化 
	} 
	
		f=k;
		while(f!=0){
			se*=10; 
			if(f>=sec){
				f=f-sec;
				se+=1;
			}
			sec=sec/2; 
		}
		k=se;
	for(int i=1;i<=n;i++){
		if(b[i]==false){
			dfs(i,i,0);
		}
		
	}
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	return 0;
//	1 ⊕ 0 ⊕ 3 = 2
//	1    0    11
//	   1    10
//	运算为
//	1.换二进制
//	2.对齐
//	3.不同为1，相同为0 
}
