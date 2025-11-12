#include<bits/stdc++.h>
using namespace std;

struct stu{
	int x,y,z;
	int c;
}a[100010];

int n;
int ans=0;

int b[100010][10];
int f[100010][10];
int v[10];

bool cmp(stu a,stu b){
	return a.c>b.c;
}

void spb(){
	for(int i=1;i<=n;i++){
		a[i].c=a[i].x-a[i].y;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n/2;i++){
		ans+=a[i].x;
	}
	for(int i=n/2+1;i<=n;i++){
		ans+=a[i].y;
	}
	cout<<ans;
	return;
}

void dfs(int x){
	if(x>n){
		ans=max(ans,(f[x][1]+f[x][2]+f[x][3]));
//		cout<<ans<<'\n';
		return;
	}
	for(int i=1;i<=3;i++){
		if(v[i]>(n/2-1)){
			continue;
		}
		for(int j=1;j<=3;j++){
			f[x+1][j]=f[x][j];
		}
		f[x+1][i]+=b[x][i];
		v[i]++;
//		cout<<x<<" choose "<<i<<'\n';
//		cout<<i<<" got "<<v[i]<<'\n';
		dfs(x+1);
		v[i]--;
	}
	for(int i=1;i<=3;i++){
		f[x+1][i]=f[x][i];
	}
	return;
}

void meizhaole(){
	for(int i=1;i<=n;i++){
		a[i].c=a[i].x-a[i].y-a[i].z;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n/3;i++){
		ans+=a[i].x;
	}
	for(int i=n/3+1;i<=n/3*2;i++){
		ans+=a[i].y;
	}
	for(int i=n/3*2+1;i<=n;i++){
		ans+=a[i].z;
	}
	// 为什么！为什么没有平均分配的特殊性质！！！ 
	cout<<ans;
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	int T;
	cin>>T;
	while(T--){
		cin>>n;
		bool fb=true;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			b[i][1]=a[i].x,b[i][2]=a[i].y,b[i][3]=a[i].z;
			if(a[i].z!=0){
				fb=false;
			}
		}
		ans=0;
		if(fb){
			spb();
		}else if(n<=12){// lai'bu'ji'jiu'xie 30 OK ,lai'de'ji,dan'shi'bu'hui 
			for(int i=1;i<=3;i++){
				f[1][i]=0;
				v[i]=0;
			}
			dfs(1);
			cout<<ans;
		}else{
			meizhaole();
		}
		// 再也不来考CSP了，太气人了。
		// 全考场一半的人来玩游戏，另一半在暴力。造密码的CSP 
		cout<<'\n';
	} 
	return 0;
}
