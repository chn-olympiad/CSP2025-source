#include<bits/stdc++.h>
using namespace std;
struct aa{
	string s1,s2;
	int s;
};
aa a[200005];

int b,c,d,e,f,g;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>b>>c;
	for(int i=1;i<=b;i++){
		cin>>a[i].s1>>a[i].s2;
		a[i].s=a[i].s1.size();
	}
	while(c--){
		string s3,s4;
		cin>>s3>>s4;
		
		int l=-1,r=0,h=0,lo;
		for(int i=0;i<s3.size();i++){
			if(s3[i]!=s4[i]){
				if(l==-1){
					l=i;
				}
				r=i;
			}
		}
		lo=r-l+1;
		for(int i=1;i<=b;i++){
			if(a[i].s>=lo&&a[i].s<=min(s3.size(),s4.size())){
				for(int j=0;j<=min(s3.size(),s4.size())-a[i].s;j++){
					int n=0;
				
					while(n>=0&&n<a[i].s){
						if(s3[j+n]==a[i].s1[n]&&s4[j+n]==a[i].s2[n]){
							
							n++;
						}else{
							n=-1;
						}
					}
					if(n==a[i].s){
						h++;
					
					}
				}
			}
		}
		cout<<h<<endl;
	}
} 
