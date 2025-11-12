#include<bits/stdc++.h>
using namespace std;
int n,m,s[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a=n*m;
	for(int i=0;i<a;i++)
		cin>>s[i];
	int s1=s[0];
	sort(s,s+a);
	int h=0,l=0;
	for(int i=0;i<a;i++){
		if(s[i]==s1){
			h=i%n;
			if(h==0){
			    l=i/n;
				if(l%2==0){
					h=1;
				}else{
					h=n;
				}
			}else{
				l=i/n+1;
				if(l%2==0){
					h=n-i%n+1;
				}else{
					h=i%n;
			}
		}
	}
	cout<<h<<" "<<l;
	fclose(stdin);
	fclose(stdout);
	return 0;
}