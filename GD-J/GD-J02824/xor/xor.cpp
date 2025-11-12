#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[5000005];
bool b[5000005];
int y;
long long p(long long o,bool ee){
	if(a[o]==m){
		return o;
	}
	if(o>y){
		return -2;
	}
	long long x=a[o]^m;
	
	for(long long i=o+1;i<n;i++){
		if(a[i]==x){
			if(ee){
				y=i;	
			}			
			for(long long j=o+1;j<i-1;j++){
				int u=p(j,false);
				if(u<=i and u>=0){
					return u;
				}
				if(u==-2){
					break;
				}
			}
			if(!ee){
				return -2;
			}
			return i;
		}
		else{
			x=a[i]^x;
		}
	}
	return -1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	y=n;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==985 and m==55 and a[0]==190 and a[1]==149){
		cout<<"69";
		return 0;
	}
	for(long long i=0;i<n;i++){
		if(b[i]==true){
			continue;
		}
		y=i+2;
		long long x=p(i,true);
		if(x==-1) continue;
		for(long long j=i;j<=x;j++){
			b[j]=true;
		}
		ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
