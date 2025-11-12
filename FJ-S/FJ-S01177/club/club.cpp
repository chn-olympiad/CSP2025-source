#include<bits/stdc++.h>
using namespace std;
struct member{
	int h1,h2,h3;
};
bool hhh(struct member x,struct member y){
	if(x.h1!=y.h1){
		return x.h1>y.h1;
	}
	else{
		if(x.h2!=y.h2){
			return x.h2>y.h2;
		}
		else
			return x.h3>y.h3;
	}
}

int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		int n,sum=0,c[4]={0,0,0,0};
		cin>>n;
		struct member m[n+3];
		for(int j=0;j<n;j++){
			cin>>m[j].h1>>m[j].h2>>m[j].h3;
		}
		sort(m,m+n,hhh);
		for(int j=0;j<n;j++){
			if(m[j].h1>m[j].h2&&m[j].h1>m[j].h3&&c[1]<n/2){
				sum+=m[j].h1;
				c[1]++;
			}
			else if(m[j].h2>m[j].h3&&c[2]<n/2){
				sum+=m[j].h2;
				c[2]++;
			}
			else{
				sum+=m[j].h3;
				c[3]++;
			}
		}
		cout<<sum<<endl;
	}
}
