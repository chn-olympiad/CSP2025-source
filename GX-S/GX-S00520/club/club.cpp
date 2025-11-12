#include<bits/stdc++.h>
using namespace std;
int n;
long long a[100007][5];
struct ze{
	int b=0,c=0;
	int i=0,ss=0;
};
int ff(ze c,ze b){
	return c.ss<=b.ss;
}
void aaa(){
	cin>>n;
	ze b[n+4]={0},c[n+4]={0};
	long long b1=0,c1=0;
	for(int i=1;i<=n;i++){
		cin>>a[i][1];
		cin>>a[i][2];
		cin>>a[i][3];
		if(a[i][1]>=a[i][2]){
			b1+=a[i][1];
			b[0].b++;
			b[b[0].b].c=a[i][2];
			b[b[0].b].b=a[i][1];
			b[b[0].b].ss=a[i][1]-a[i][2];
		}else{
			c1+=a[i][2];
			c[0].c++;
			c[c[0].c].b=a[i][1];
			c[c[0].c].c=a[i][2];
			c[c[0].c].ss=a[i][2]-a[i][1];
		}
	}
	sort(b+1,b+b[0].b+1,ff);
	sort(c+1,c+c[0].c+1,ff);
	if(b[0].b>=n/2){
		for(int i=1;i<=b[0].b-n/2;i++){
			b1-=b[i].ss;
		}
	}else
	if(c[0].c>=n/2){
		for(int i=1;i<=c[0].c-n/2;i++){
			c1-=c[i].ss;
		}
	}
	cout<<b1+c1<<endl;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		aaa();
	}
return 0;
}
