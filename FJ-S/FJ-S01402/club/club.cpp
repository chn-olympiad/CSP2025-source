#include<bits/stdc++.h>
using namespace std;
int n,t,a1=0,a2=0,a3=0,ans=0;
struct ss{
	int n1,n2,n3;
};
ss s[100005];
bool camp(ss a,ss b){
	return a.n1>b.n1;
};
bool cmp(ss a,ss b){
	return a.n2>b.n2;
};
bool cmpn(ss a,ss b){
	return a.n3>b.n3;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int j=1;j<=n;j++){
		cin>>t;
		int x=t,c=t/2;
		ans=0,a1=0,a2=0;
		for(int i=1;i<=t;i++){
			cin>>s[i].n1>>s[i].n2>>s[i].n3;
		}
		sort(s+1,s+t+1,camp);
		t=x;
	    for(int i=1;i<=t;i++){
	    	if(a1>=c) break;
	    	if(s[i].n1>=s[i].n3&&s[i].n1>=s[i].n2){
	    		ans+=s[i].n1;
	    		x--;
	    		a1++;
	    		s[i].n1=0,s[i].n2=0,s[i].n3=0;
	    	}
		}
		sort(s+1,s+t+1,cmp);
		t=x;
	    for(int i=1;i<=t;i++){
	    	if(a2>=c) break;
	    	if(s[i].n2>=s[i].n3&&s[i].n2>=s[i].n1){
	    		ans+=s[i].n2;
	    		x--;
	    		a2++;
	    		s[i].n1=0,s[i].n2=0,s[i].n3=0;
	    	}
		}
		sort(s+1,s+t+1,cmpn);
		t=x;
	    for(int i=1;i<=t;i++){
	    	if(a3>=c) break;
	    	if(s[i].n3>=s[i].n1&&s[i].n3>=s[i].n2){
	    	ans+=s[i].n3;
	    		x--;
	    		a3++;
	    		s[i].n1=0,s[i].n2=0,s[i].n3=0;
	    	}
		}
		while(x>0){
		sort(s+1,s+t+1,camp);
		t=x;
	    for(int i=1;i<=1;i++){
	    	if(a1>=c) break;
	    		ans+=s[i].n1;
	    		x--;
	    		a1++;
	    		s[i].n1=0,s[i].n2=0,s[i].n3=0;
		}
		sort(s+1,s+t+1,cmp);
		t=x;
	    for(int i=1;i<=1;i++){
	    	if(a2>=c) break;
	    		ans+=s[i].n2;
	    		x--;
	    		a2++;
	    		s[i].n1=0,s[i].n2=0,s[i].n3=0;
		}
		sort(s+1,s+t+1,cmpn);
		t=x;
	    for(int i=1;i<=1;i++){
	    	if(a3>=c) break;
	    	ans+=s[i].n3;
	    		x--;
	    		a3++;
	    		s[i].n1=0,s[i].n2=0,s[i].n3=0;
		}
	}
		cout<<ans<<endl;
	}
	
	return 0;
}