#include<iostream>
using namespace std;
int main(){
	    int n,m,k,sum1=0;
		cin>>n>>m>>k;
		if(n<m&&n<k){
		   	sum1+=n;
		}else if(m<n&&m<k){
			sum1+=m;
		}else if(k<n&&k<m){
			sum1+=k;
		}
		int u,v,w,sum2=0;
		cin>>u>>v>>w;
		if(u<v&&u<w){
		   	sum2+=u;
		}else if(v<u&&v<w){
			sum2+=v;
		}else if(w<u&&w<v){
			sum2+=w;
		}
		int a,b,c,sum3=0;
		cin>>a>>b>>c;
		if(a<b&&a<c){
		   	sum3+=a;
		}else if(b<a&&b<c){
			sum3+=b;
		}else if(c<a&&c<b){
			sum3+=c;
		}
		int i,j,d,sum4=0;
		cin>>i>>j>>d;
		if(i<j&&i<d){
		   	sum4+=i;
		}else if(j<i&&j<d){
			sum4+=j;
		}else if(d<i&&d<j){
			sum4+=d;
		}
		int e,f,g,sum5=0;
		cin>>e>>f>>g;
		if(e<f&&e<j){
		   	sum5+=e;
		}else if(f<e&&f<g){
			sum5+=f;
		}else if(g<e&&g<f){
			sum5+=g;
		}
		int q1,q2,q3,sum6=0;
		cin>>q1>>q2>>q3;
		if(q1<q2&&q1<q3){
		   	sum6+=q1;
		}else if(q2<q1&&q2<q3){
			sum6+=q2;
		}else if(q3<q1&&q3<q2){
			sum6+=q3;
		}
		int x1,x2,x3,sum7=0;
		cin>>x1>>x2>>x3;
		if(x1<x2&&x1<x3){
		   	sum7+=x1;
		}else if(x2<x1&&x2<x3){
			sum7+=x2;
		}else if(x3<x1&&x3<x2){
			sum7+=x3;
		}
	
	cout<<sum1+sum2+sum3+sum4+sum5+sum6+sum7+1;
	return 0;
} 
