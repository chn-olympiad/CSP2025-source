#include<bits/stdc++.h>
using namespace std;
string s1,s2;
string b1,b2;
int t,n,v,ans,i,j,f,m,o,p,e,t1,w;
int w2,v2,l1,l2;
struct z{
	string x,y;
	int s;
}a[100010];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n;i++){
	    cin>>a[i].x>>a[i].y;
	    a[i].s=a[i].x.size();	
	}
    while(m--){
		cin>>b1>>b2;
		t=b1.size(); 
		s1="";
		v=0; 
		ans=0;   
		for(i=0;i<t;i++){
		    if(b1[i]!=b2[i]){
				if(s1==""){
				    s1=s1+b1[i];
				    s2=s2+b2[i];
				    w=i;
				    v=i;
				}else{
				    for(j=v+1;j<=i;j++){
					    s1=s1+b1[j];
					    s2=s2+b2[j];	
					}	
					v=i;
				}
			}	
		} 
		t1=v-w+1;
		for(i=1;i<=n;i++){
		    o=0;
		    p=0;
		    if(a[i].s>t1){
				continue;
			}
		    for(j=0;j<a[i].s;j++){
				if(p>t){
					v2=j-1;
					break;
				}
				if(a[i].x[j]==s1[p]&&a[i].y[j]==s1[p]&&o==0){
					o=1;
					w2=j;
					p++;
				}else if(a[i].x[j]==s1[p]&&a[i].y[j]==s1[p]&&o==1){
					o=1;
					p++;
				}else if(a[i].x[j]!=s1[p]&&o==1){
					o=0;
					p=0;
				}else if(a[i].y[j]==s1[p]&&o==0){
					o=0;
					p=0;
				}
			}	
			if(p!=t){
			    o=0;	
			}
			if(o==1){
			   	l1=w2;
			   	l2=a[i].s-v2;
			   	o=0;
			   	p=0;
			   	for(j=w-l1;j<=w-1;j++){
					if(b1[j]==a[i].x[p]){
						o=1;
					}else{
						o=0;
					}
				}
				if(o==1){
					p=a[i].s;
    			   	for(j=v+l2;j<=w-1;j++){
					    if(b1[j]==a[i].x[p]){
					    	o=1;
					    }else{
						    o=0;
					    }
				    }
				    if(o==1){
						ans++;
					}	
				}
			}
		}
		cout<<ans<<endl;   
	}
    return 0;
}
