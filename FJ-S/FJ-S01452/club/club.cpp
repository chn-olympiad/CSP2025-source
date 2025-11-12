#include<bits/stdc++.h>
using namespace std;
int n,T;
struct stu{
	int a[4];
	int mx,mxnum;
	int mn1=30000;
}stus[100010];

bool cmp(int a,int b){
	return stus[a].mn1<stus[b].mn1;
}

int gt(){
	int ans=0;
	char a=getchar();
	while(a>='0'&&a<='9'){
		ans=ans*10+a-'0';
		a=getchar();
	}
	return ans;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	T=gt();
	while(T--){
		int ans=0;
		n=gt();
		int c[4]={0};
		vector<int> cs[4];
		for(int i=1;i<=n;i++){
			stus[i].mn1=30000;
			stus[i].a[1]=gt();
			stus[i].a[2]=gt();
			stus[i].a[3]=gt();
			stus[i].mx=max(max(stus[i].a[1],stus[i].a[2]),stus[i].a[3]);
			for(int j=1;j<=3;j++){
				if(stus[i].mx==stus[i].a[j]){
					stus[i].mxnum=j;
					break;
				}
			}
			for(int j=1;j<=3;j++){
				if(j!=stus[i].mxnum&&stus[i].mx-stus[i].a[j]<stus[i].mn1){
					stus[i].mn1=stus[i].mx-stus[i].a[j];
				}
			}
			c[stus[i].mxnum]++;
			cs[stus[i].mxnum].push_back(i);
			ans+=stus[i].mx;
		}
		int mxc=0,mxcn=0;
		for(int i=1;i<=3;i++){
			if(c[i]>mxc){
				mxc=c[i];
				mxcn=i;
			}
		}
		sort(cs[mxcn].begin(),cs[mxcn].end(),cmp);
		if(c[mxcn]>n/2){
			int tms=c[mxcn]-n/2;
			for(int i=0;i<tms;i++){
				ans-=stus[cs[mxcn][i]].mn1;
			}	
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
