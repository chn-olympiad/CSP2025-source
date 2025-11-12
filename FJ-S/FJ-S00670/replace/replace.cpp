#include <bits/stdc++.h>
using namespace std;
string s1,s2,t1,t2;
int s[200010][2][3],t,ans,n,q;
int f(string s1,string s2){
	int n1,n2;
	for(int i=0;i<s1.length();i++){
		if(s1[i]=='b'){
			n1=i;
			break;
		}
	}
		for(int i=0;i<s2.length();i++){
		if(s2[i]=='b'){
		   if(s2[i]=='b'){
		   n2=i;
		   break;
		}
		}
	}
	int ans=n2-n1;
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		s[i][0][0]=f(s1,s2);
		for(int j=0;j<s1.length();j++){
		    if(s1[j]=='b'){
			   s[i][0][1]=j;
			   s[i][0][2]=s1.length()-j;
			   break;
		    }
	    }
		for(int j=0;j<s2.length();j++){
		    if(s2[j]=='b'){
		       s[i][1][1]=j;
		 	   s[i][1][2]=s2.length()-j;
		       break;
		    }
	    }
	} 
	while(q--){
		cin>>t1>>t2;
		int l1,r1,l2,r2;
	        for(int j=0;j<t1.length();j++){
		        if(t1[j]=='b'){
			       l1=j;
			       r1=t1.length()-j;
			       break;
		        }
	        }
		    for(int j=0;j<t2.length();j++){
		        if(t2[j]=='b'){
		           l2=j;
		 	       r2=t2.length()-j;
		           break;
		        }
	        }
		t=f(t1,t2);
			for(int i=1;i<=n;i++){
				if(s[i][0][0]==t && l1>=s[i][0][1] && r1>=s[i][0][2] && l2>=s[i][1][1] && r2>=s[i][1][2]) ans++;
			}
		printf("%d\n",ans);
		ans=0; 
	}
	return 0;
}
