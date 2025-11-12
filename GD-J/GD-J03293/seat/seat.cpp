#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Max 1005
ll n,m,d,num;
ll a[Max][Max]; 
int mumber[Max*Max];
ll ans_name,ans_num;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>m>>n;
    d=1;
    for(int i=0;i<n;i++){
       	for(int j=0;j<m;j++){
       		if(d==1)
       		num++;
       		if(d==2)
       		num--;
			a[i][j]=num;
		}	
		if(d==1) num+=m+1,d=2;
		else num+=m-1,d=1;
	}
	cin>>ans_name;
	num=1;
	for(int i=1;i<n*m;i++){
		cin>>mumber[i];
		if(mumber[i]>ans_name){
			num++;
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[j][i]==num){
			cout<<j+1<<" "<<i+1;	
			}
		}
	}
    
	return 0;
} 
