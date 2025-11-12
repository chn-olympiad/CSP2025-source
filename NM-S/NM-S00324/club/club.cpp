#include<bits/stdc++.h>
using namespace std;
long long a[101000];
long long b[101000];
long long c[101000];
int an[101000];
int bn[101000];
int cn[101000];
int stu[101000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,num=0,aa=0,bb=0,cc=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		for(int i=0;i<n;i++){
			int maxn;
		    if(aa<(n/2)&&bb<(n/2)&&cc<(n/2)){
		    	maxn=max(a[i],b[i]);
		    	int ll=c[i];
		        maxn=max(maxn,ll);
			}
			else if(aa<(n/2)&&bb<(n/2)){
				maxn=max(a[i],b[i]);
			}
		    else if(aa<(n/2)&&cc<(n/2)){
				maxn=max(a[i],c[i]);
			}
			else if(cc<(n/2)&&bb<(n/2)){
				maxn=max(c[i],b[i]);
			}
		    if(a[i]==maxn){
			    stu[i]=1;
			    an[i]==1;
			    aa++;
		    } 
		    else if(b[i]==maxn){
			    stu[i]=2;
			    bn[i]=1;
			    bb++;
		    }
		    else if(c[i]==maxn){
			    stu[i]=3;
			    cn[i]=1;
			    cc++;
		    }
		    num+=maxn;
		}
		cout<<num<<endl;
	}
	return 0;
}
