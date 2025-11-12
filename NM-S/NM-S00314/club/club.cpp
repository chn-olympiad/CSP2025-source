#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b;
}a[100010][3];
struct noe{
	int a1,a2,a3,b1,b2,b3,c;
}b[100010];
 bool cmp(noe x,noe y){
 	if(x.c!=y.c)return x.c>y.c;
 	else if(x.a1!=y.a1) return x.a1>y.a1; 
 	else if(x.a2!=y.a2) return x.a2>y.a2; 
 	else return x.a3>y.a3; 
 }
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long n=0,t,cnt=0;
    cin>>t;
    while(t--){
    	cnt=0;int bm[3]={};
    	cin>>n;
    	for(int i=0;i<n;i++)for(int j=0;j<3;j++){
    		cin>>a[i][j].a;
    		a[i][j].b=j;
		}
    	for(int i=0;i<n;i++){
    		for(int j=1;j<3;j++)if(a[i][j].a>a[i][j-1].a){
    			swap(a[i][j].a,a[i][j-1].a);
    			swap(a[i][j].b,a[i][j-1].b);
			}
    		if(a[i][1].a>a[i][0].a){
    			swap(a[i][1].a,a[i][0].a);
    			swap(a[i][1].b,a[i][0].b);
			}
    		b[i].c=a[i][0].a-a[i][1].a;
    		b[i].b1=a[i][0].b;
    		b[i].b2=a[i][1].b;
    		b[i].b3=a[i][2].b;
    		b[i].a1=a[i][0].a;
    		b[i].a2=a[i][1].a;
    		b[i].a3=a[i][2].a;
		}
		sort(b,b+n,cmp);
		for(int i=0;i<n;i++){
			if((bm[b[i].b1]+1)<=n/2){
			bm[b[i].b1]++;
			cnt+=b[i].a1;
			}
			else {
			bm[b[i].b2]++;
			cnt+=b[i].a2;
			}
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);	   
    return 0;
}

