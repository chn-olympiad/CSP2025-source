#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int t;
cin>>t;
int st[t];
for(int i=0;i<t;i++){
	int n,st1rs=0,st2rs=0,st3rs=0;
	cin>>n;
	int a[t][3];
	for(int j=0;j<n;j++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(st1rs<(n/2)){
			if(a[i][1]>a[i][2] && a[i][1]>a[i][3]){
				st[i]+=a[i][1];
				st1rs++;
			}
		}else if(st2rs<(n/2)){
			if(a[i][2]>a[i][3]){
				st[i]+=a[i][1];
				st2rs++;
			}
		}else if(st3rs<(n/2)){
			if(a[i][3]>a[i][1] && a[i][3]>a[i][2]){
				st[i]+=a[i][3];
				st3rs++;
			}
		}
	}
}
for(int i=0;i<t;i++){
	cout<<st[i]<<endl;
}
return 0;
}
