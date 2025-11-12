#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int f=0,r,s[n*m];
	for(int i=0;i<n*m;i++)cin>>s[i];
	r=s[0];
	sort(s,s+n*m,cmp);
	int i=0,h=1,l=1;
	while(s[i]!=r){
		//cout<<l<<' '<<h<<endl;
		if(f==0)h++;
		else h--;
		if(h==0 || h==n+1){
			f=1-f;
			if(h==0)h=1;
			else h=n;
			l++;
		}
		i++;
	}
	cout<<l<<' '<<h;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
