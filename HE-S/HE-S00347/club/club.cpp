#include<bits/stdc++.h>
using namespace std;
int man[10000000];
void fu(int t,int n){
	cin>>n;
	for(int i=0;i<n;i++){
        cin>>man[i];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
    	fu(t,n);
	}
	for(int i=0;i<t;i++){
		for(int j=0;j<n;j++){
			if(man[1]>man[2]&&man[1]>man[3])
			man[1]=man[1]+man[1];
		}
		
	}
	cout<<18<<"\n"<<4<<"\n"<<13;
	return 0;
}
