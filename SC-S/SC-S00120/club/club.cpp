#include<bits/stdc++.h>
using namespace std;
void f(){
	int n,ac,bc,cc,mc,q[4]={},hg=0,hg_=0;
	cin>>n;
	vector<int>a,b,c,m,d,s;
	for(int i=0;i<n;i++){
		cin>>ac>>bc>>cc;
		a.push_back(ac);
		b.push_back(bc);
		c.push_back(cc);
		hg+=max(ac,max(bc,cc));
		mc=1;
		if(bc>ac){
			mc=2;
			ac=bc;
		}
		if(cc>ac){
			mc=3;
			cc=ac;
		}
		d.push_back(mc);
		q[mc]++;
	}
	if(q[1]*2<=n&&q[2]*2<=n&&q[3]*2<=n){
		cout<<hg<<endl;
		return;
	}
	else{
		if(q[1]*2>n){
			for(int i=0;i<n;i++){
				if(d[i]==1){
					s.push_back(min(a[i]-b[i],a[i]-c[i]));
				}
			}
			sort(s.begin(),s.end()); 
			for(int i=0;i<q[1]-n/2;i++){
				hg_+=s[i];
			}
		}
		if(q[2]*2>n){
			for(int i=0;i<n;i++){
				if(d[i]==2){
					s.push_back(min(b[i]-a[i],b[i]-c[i]));
				}
			}
			sort(s.begin(),s.end()); 
			for(int i=0;i<q[2]-n/2;i++){
				hg_+=s[i];
			}
		}
		if(q[3]*2>n){
			for(int i=0;i<n;i++){
				if(d[i]==3){
					s.push_back(min(c[i]-a[i],c[i]-b[i]));
				}
			}
			sort(s.begin(),s.end()); 
			for(int i=0;i<q[3]-n/2;i++){
				hg_+=s[i];
			}
		}
		cout<<hg-hg_<<endl;
		return;
	}
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		f();
	}
	return 0;
}