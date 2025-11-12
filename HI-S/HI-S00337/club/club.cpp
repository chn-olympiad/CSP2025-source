#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct Student{
	int a,b,c,mn,mn2;
}p[N];
int n,ans;
bool cmp(Student A,Student B){
	return (A.mn-A.mn2)>(B.mn-B.mn2);
}
void init(){
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i].a>>p[i].b>>p[i].c;
		p[i].mn=max(p[i].a,max(p[i].b,p[i].c));
		if(p[i].mn==p[i].a)p[i].mn2=max(p[i].b,p[i].c);
		else if(p[i].mn==p[i].b)p[i].mn2=max(p[i].a,p[i].c);
		else p[i].mn2=max(p[i].a,p[i].b);
	}
	sort(p+1,p+1+n,cmp);
//	for(int i=1;i<=n;i++){
//		cout<<p[i].a<<" "<<p[i].b<<" "<<p[i].c<<" "<<p[i].mn<<" "<<p[i].mn2<<"\n";
//	}
	int cnta=0,cntb=0,cntc=0;
	for(int i=1;i<=n;i++)
		if(p[i].mn==p[i].a)
			if(cnta>=n/2){
				if(p[i].mn2==cntb)cntb++;
				else cntc++;
				ans+=p[i].mn2;
			}
			else{
				cnta++;
				ans+=p[i].mn;
			}
		else if(p[i].mn==p[i].b)
			if(cntb>=n/2){
				if(p[i].mn2==cnta)cnta++;
				else cntc++;
				ans+=p[i].mn2;
			}
			else{
				cntb++;
				ans+=p[i].mn;
			}
		else
			if(cntc>=n/2){
				if(p[i].mn2==cntb)cntb++;
				else cnta++;
				ans+=p[i].mn2;
			}
			else{
				cntc++;
				ans+=p[i].mn;
			}
	cout<<ans<<"\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)init();
	return 0;
}

