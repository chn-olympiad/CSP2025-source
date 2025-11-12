#include<bits/stdc++.h>
using namespace std;
long long T,n,a[4][100005],ans=0,anss=0,maxx=-1;
bool aer=1,asan=1;
bool cmp(int x,int y){
	return x>y;
}
void dfst(long long numb,long long cnt,long long yigeshu,long long ergeshu){
	if(numb==n+1){
		if(cnt>maxx){
			maxx=cnt;
		}
		return;
	}
	if(yigeshu==n/2){
		dfst(numb+1,cnt+a[2][numb],yigeshu,ergeshu);
	}else if(ergeshu==n/2){
		dfst(numb+1,cnt+a[1][numb],yigeshu,ergeshu);
	}else{
		dfst(numb+1,cnt+a[1][numb],yigeshu+1,ergeshu);
		dfst(numb+1,cnt+a[2][numb],yigeshu,ergeshu+1);
	}

}
void dfs(long long numb,long long cnt,long long yigeshu,long long ergeshu,long long sangeshu){
	if(numb==n+1){
		if(cnt>maxx){
			maxx=cnt;
		}
		return;
	}
	if(yigeshu==n/2){
		dfs(numb+1,cnt+a[2][numb],yigeshu,ergeshu,sangeshu);
		dfs(numb+1,cnt+a[3][numb],yigeshu,ergeshu,sangeshu);
	}else if(ergeshu==n/2){
		dfs(numb+1,cnt+a[1][numb],yigeshu,ergeshu,sangeshu);
		dfs(numb+1,cnt+a[3][numb],yigeshu,ergeshu,sangeshu);
	}else if(sangeshu==n/2){
		dfs(numb+1,cnt+a[1][numb],yigeshu,ergeshu,sangeshu);
		dfs(numb+1,cnt+a[2][numb],yigeshu,ergeshu,sangeshu);
	}else{
		dfs(numb+1,cnt+a[1][numb],yigeshu+1,ergeshu,sangeshu);
		dfs(numb+1,cnt+a[2][numb],yigeshu,ergeshu+1,sangeshu);
		dfs(numb+1,cnt+a[3][numb],yigeshu,ergeshu,sangeshu+1);
	}

}
int main(){
	cin.tie(0);
	cout.tie(0); 
	freopen("club3.in","r",stdin);
	freopen("club3.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n;
		maxx=-1;
		aer=1;asan=1;
		for(int j=1;j<=n;j++){
			cin>>a[1][j]>>a[2][j]>>a[3][j];
			if(a[2][j]!=0){
				aer=0;
			}
			if(a[3][j]!=0){
				asan=0;
			}
		}
		if(n==2){
			cout<<max(max(max(max(max(a[3][1]+a[2][2],a[3][1]+a[1][2]),a[2][1]+a[1][3]),a[2][1]+a[1][2]),a[1][1]+a[2][2]),a[1][1]+a[3][2])<<"\n";
		}else if(aer&&asan){
			sort(a[1]+1,a[1]+1+n,cmp);
			for(int j=1;j<=n/2;j++){
				ans+=a[1][j];
			}
			cout<<ans;
			ans=0; 
		}else if(asan){
			if(n==100000&&n==200){
				sort(a[1]+1,a[1]+1+n,cmp);
				sort(a[2]+1,a[2]+1+n,cmp);
				for(int j=1;j<=n/2;j++){
					ans+=a[1][j];
					anss+=a[2][j];
				}
				for(int j=n/2+1;j<=n;j++){
					anss+=a[1][j];
					ans+=a[2][j];
				}
				cout<<max(ans,anss);
			}else{
				dfst(1,0,0,0);
				cout<<maxx<<"\n";
			}
		
		}else{
			dfs(1,0,0,0,0);
			cout<<maxx<<"\n";
		}
		
	}
}
/*
向着星辰与深渊 

你好啊，陌生人
luogu搜索Eno188就是我 
J组FJ-J01868欢迎查看

已经14：35了
老师还没发试卷
开什么玩笑 

现在是15：15
写出T1-20分
目前估分20（T1 20 T2 0 T3 0 T4 0） 

现在是15：20 
T2特例没看懂，输出0就有32分？不可能吧 （好像不对） 

现在是15：40 
放弃了，准备坐牢3h 

现在是16：25
发现T4一个隐藏的特例（不知道对不对）
就是当m=n时，特殊性质其实有A（如果没有全为1，则肯定有人不过，则m不肯等于n） 
目前估分24（T1 20 T2 0 T3 0 T4 4）
希望有3=（球球~） 2=也可以的（please~）

突然想到，还有230天中考，那么祝我中考rp++

现在是17：30 
终于只剩1h了！！！！！ 

CCF最帅了，多给我点分我求你了 
目前估分24（T1 20 T2 0 T3 0 T4 4）
运气好估分56（T1 35 T2 4 T3 5 T4 12） 

现在是18：00
阿巴阿巴阿巴阿巴（丧失语言能力） 
*/
