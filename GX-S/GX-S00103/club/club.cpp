#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t,n,x;
    cin>>t;
    vector <int> a,b,c,d;
    int e[t]={},f[6]={};
    for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			for(int k=0;k<3;k++){
			    cin>>x;
				if(k==0) a.push_back(x);
				else if(k==1) b.push_back(x);
				else c.push_back(x);
			}
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		sort(c.begin(),c.end());
		
	    for(int p=0;p<n/3;p++) {
			int y=a.back()+b.back()+c.back();
			a.pop_back();
			b.pop_back();
			c.pop_back();
			e[i]+=y;
			y=0;
		}
		if(n%3==1){
			if(a.back()<b.back() and b.back()<c.back()) e[i]+=c.back();
			else if(a.back()<b.back() and b.back()>c.back()) e[i]+=b.back();
			else e[i]+=a.back();
		}
		if(n%3==2 and n!=2){
			if(a.back()<b.back() and b.back()<c.back()) e[i]=e[i]+c.back()+b.back();
			else if(a.back()>b.back() and b.back()>c.back()) e[i]=e[i]+b.back()+a.back();
			else e[i]=e[i]+a.back()+c.back();
		}
		if(n==2){
			int a1=a.front()+b.back();
			int a2=a.front()+c.back();
			int a3=b.front()+a.back();
			int a4=b.front()+c.back();
			int a5=c.front()+a.back();
			int a6=c.front()+b.back();
			f[0]=a1;
			f[1]=a2;
			f[2]=a3;
			f[3]=a4;
			f[4]=a5;
			f[5]=a6;
			auto o=max_element(f,f+6);
			e[i]+=*o;
		}
		while(!a.empty()) {
			a.pop_back();
			b.pop_back();
			c.pop_back();
		}
	}
	for(auto x:e) cout<<x<<endl;
    return 0;
}
