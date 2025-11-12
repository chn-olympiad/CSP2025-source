#include <bits/stdc++.h>
using namespace std;
int n;
struct dad{
	int a,b,c;
};
dad po[100001];
bool cmp(dad as,dad bs){
	int d1=as.a+as.b+as.c;
	int d2=bs.a+bs.b+bs.c;
	if(d1>d2){
		return true;
	}
	else return false;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		int cnt=0;
		for(int i=1;i<=n;i++){
			cin>>po[i].a>>po[i].b>>po[i].c;
		}
		sort(po+1,po+n+1,cmp);
		int a1=0,b1=0,c1=0;
		for(int i=1;i<=n;i++){
			if(po[i].a>po[i].b&&po[i].c<po[i].a&&a1!=n/2){
				a1++;
				cnt+=po[i].a;
			}
			else if(po[i].a<po[i].b&&po[i].b>po[i].c&&b1!=n/2){
				cnt+=po[i].b;
				b1++;
			}
			else {
				c1++;
				cnt+=po[i].c;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
} 
