#include<bits/stdc++.h>
using namespace std;
int suma=0,sumb=0;
int n,m,sum;
struct a{
	int yi,er,san;
	bool zq=true,zw,ze,zhen;
}s[100009];
int cmpa(a q,a w){
	return q.yi>w.yi;
}
int cmpb(a q,a w){
	return q.er>w.er;
}
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		sum=0;
		cin>>n;
		m=n/2;
		int v=1;
		int zzz=0;
	for(int i=1;i<=n;i++){
		cin>>s[i].yi >>s[i].er >>s[i].san ;
		s[i].zq  =true;	s[i].ze  =true;	s[i].zw =true;	s[i].zhen  =true;
		if(s[i].er==0&&s[i].san==0){
		sum+=s[i].yi;
		s[i].zhen =false;
		zzz++;
		}
		if(s[i].san >s[i].yi &&s[i].san >s[i].er){
			s[i].ze =false;
		}
	}
	sort(s+1,s+1+n,cmpa);
	int f=m;
	for(int i=1;i<=f-zzz;i++){
		if(s[i].zhen ){
			sum+=s[i].yi ;
//			cout<<s[i].yi ;
		    s[i].zhen =false;
		    s[i].zq =false;
		}
		else {
			f++;
		}
	}
	sort(s+1,s+1+n,cmpb);
	int ff=m;
	for(int i=1;i<=ff;i++){
		if(s[i].zhen ){
		sum+=s[i].er;
//			cout<<s[i].er  ;
		s[i].zhen  =false;
	    s[i].zw  =false;
		}
		else if(s[i].er >s[i].yi ){
			sum+=s[i].er-s[i].yi;
//			cout<<s[i].er  ;
		}
		else {
			ff++;
		}
	}
	for(int i=1;i<=n;i++){
		if(!s[i].ze){
			if(!s[i].zq)sum+=s[i].san -s[i].yi ;
			else if(!s[i].zw)sum+=s[i].san -s[i].er ;
		}
	}
	cout<<sum<<endl;
    }   
	return 0;
}
