#include<bits/stdc++.h>
using namespace std;
int jr(int a,int b,int c){
	if(a>b&&a>c)return 0;
	if(b>a&&b>c)return 1;
	return 2;
}
int je(int a,int b,int c,int q){
	if(q==0){
		if(b>c)return 1;
		return 2; 
	}else if(q==1){
		if(a>c)return 0;
		return 2;
	}
	if(a>b)return 0;
	return 1;
}
void sd(){
	int n,g,s[3]={},z[3]={},d,l;
	cin>>n;
	g=n/2;
	int a[n][4];
	for(int i=0;i<n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		a[i][3]=jr(a[i][0],a[i][1],a[i][2]);
	}
	s[a[0][3]]+=a[0][a[0][3]];
	z[a[0][3]]++;
	for(int i=1;i<n;i++){
		if(z[a[i][3]]>=g){
			if(a[i-1][3]==a[i][3]){
				d=a[i][3]; if(a[i-1][a[i-1][3]]!=a[i][a[i][3]])l=i-1;
				if(a[i-1][d]+a[i][je(a[i][0],a[i][1],a[i][2],d)]>a[i][d]+a[i-1][je(a[i-1][0],a[i-1][1],a[i-1][2],d)]){	
					s[je(a[i][0],a[i][1],a[i][2],d)]+=a[i][je(a[i][0],a[i][1],a[i][2],d)];
					z[je(a[i][0],a[i][1],a[i][2],d)]++;
				}else{
					s[d]-=a[i-1][d];
					s[d]+=a[i][d];
					s[je(a[i-1][0],a[i-1][1],a[i-1][2],d)]+=a[i-1][je(a[i-1][0],a[i-1][1],a[i-1][2],d)];
					z[je(a[i-1][0],a[i-1][1],a[i-1][2],d)]++;
				}
			}
		}else{
			s[a[i][3]]+=a[i][a[i][3]];
			z[a[i][3]]++;
		}
	}
	cout<<s[0]+s[1]+s[2]<<endl;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++)sd();
	
	return 0;
}
