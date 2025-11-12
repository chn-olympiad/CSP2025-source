#include<bits/stdc++.h>
using namespace std;
struct student{
	int a,b,c;
}s[100050];
bool cmpa(student n,student m){
	return min(abs(n.b-n.a),abs(n.a-n.c))>min(abs(m.b-m.a),abs(m.a-m.c));
}
bool cmpb(student n,student m){
	return min(abs(n.b-n.a),abs(n.b-n.c))>min(abs(m.b-m.a),abs(m.b-m.c));
}
bool cmpc(student n,student m){
	return min(abs(n.b-n.c),abs(n.a-n.c))>min(abs(m.b-m.c),abs(m.a-m.c));
}
int a[100050][10];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
		int n;
		cin>>n;
		int sum1=0,sum2=0,sum3=0;
		int ans1=0,ans2=0,ans3=0;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			if(s[i].a>=s[i].b&&s[i].a>=s[i].c){
				 ans1+=s[i].a;
				 sum1++;
			}
			if(s[i].b>s[i].a&&s[i].b>=s[i].c){
				 ans2+=s[i].b;
				 sum2++;
			}
			if(s[i].c>s[i].b&&s[i].c>s[i].a){
				 ans3+=s[i].c;
				 sum3++;
			}
		}
		if(sum1>n/2){
			sort(s+1,s+sum1+1,cmpa);
		    for(int i=n/2+1;i<=sum1;i++){
				if(abs(s[i].b-s[i].a)>abs(s[i].a-s[i].c)){	
				    ans1-=s[i].a;
				    ans3+=s[i].c;
				}else{
				    ans1-=s[i].a;
				    ans2+=s[i].b;
				}
		    }			
		}
		if(sum2>n/2){
			sort(s+1,s+sum2+1,cmpb);	
		    for(int i=n/2+1;i<=sum2;i++){
				if(abs(s[i].b-s[i].a)>abs(s[i].b-s[i].c)){	
				    ans2-=s[i].b;
				    ans3+=s[i].c;
				}else{
				    ans2-=s[i].b;
				    ans1+=s[i].a;
				}
		    }			
		}
		if(sum3>n/2){
			sort(s+1,s+sum2+1,cmpc);	
		    for(int i=n/2+1;i<=sum3;i++){
				if(abs(s[i].b-s[i].c)>abs(s[i].a-s[i].c)){	
				    ans3-=s[i].c;
				    ans1=s[i].a;
				}else{
				    ans3-=s[i].c;
				    ans2+=s[i].b;
				}
		    }			
		}
		//cout<<ans1<<" "<<ans2<<" "<<ans3<<" ";
		cout<<ans1+ans2+ans3<<endl;
	}
    return 0;
}
