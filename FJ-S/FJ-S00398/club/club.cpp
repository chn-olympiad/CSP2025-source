#include <bits/stdc++.h>
using namespace std;
int t,n,k,hot[4];
long long ans;
struct student{long long c1,c2,c3;bool f;}s[200000];
bool cmp1(student x,student y){return x.c1-max(x.c2,x.c3)>y.c1-max(y.c2,y.c3);}
bool cmp2(student x,student y){return x.c2-x.c3>y.c2-y.c3;}
void switch_(){
	long long m,p;
	for (int i=0;i<n;i++){
		m=max(max(s[i].c1,s[i].c2),s[i].c3);
		if(s[i].c1==m) hot[1]++;
		if(s[i].c2==m) hot[2]++;
		if(s[i].c3==m) hot[3]++;
	}
	if(hot[3]==max(max(hot[1],hot[2]),hot[3]))
		for (int i=0;i<n;i++)
			p=s[i].c1,s[i].c1=s[i].c3,s[i].c3=p;
	else if(hot[2]==max(max(hot[1],hot[2]),hot[3]))
		for (int i=0;i<n;i++)
			p=s[i].c1,s[i].c1=s[i].c2,s[i].c2=p;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin >> t;
	for (int g=0;g<t;g++){
		cin >> n;
		for (int i=0;i<n;i++) cin >> s[i].c1 >> s[i].c2 >> s[i].c3;
		for (int i=0;i<n;i++) s[i].f=false;
		ans=0,k=0,hot[1]=0,hot[2]=0,hot[3]=0;
		switch_();
		sort(s,s+n,cmp1);
		for (int i=0;i*2+2<=n;i++)
			if(s[i].c1-max(s[i].c2,s[i].c3)>=0) s[i].f=true,ans+=s[i].c1;
		sort(s,s+n,cmp2);
		for (int i=0;i<n&&k*2+2<=n;i++)
			if(s[i].c2-s[i].c3>=0&&(!s[i].f)) s[i].f=true,ans+=s[i].c2,k++;
		for (int i=0;i<n;i++)
			if(!s[i].f) ans+=s[i].c3;
		cout << ans << "\n";
	}
	return 0;
}
