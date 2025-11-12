#include<bits/stdc++.h>
using namespace std;
int hs,ls;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>hs>>ls;
    long long a=hs*ls;
    vector<vector <int> >wkx(hs,vector<int>(ls,0));
    int sr[a];
    for(int i=0;i<a;i++){
    	cin>>sr[i];
	}
	int r=sr[0];
	for(int i=0;i<a-1;i++){
		for(int j=0;j<a-i-1;j++){
			if(sr[j]<sr[j+1]){
				swap(sr[j],sr[j+1]);
			}
		}
	}
	int ans=0;
    int zuizhong1=0,zuizhong2=0;
	for(int i=0;i<a;i++){
		if(sr[i]==r){
			ans=i+1;
		}
	}
	int cs=1;
	while(cs!=ans){
		wkx[zuizhong1][zuizhong2]=cs;
		if(cs%hs==0){
			zuizhong2++;
		}
		else{
			if(wkx[zuizhong1+1][zuizhong2]==0){
				zuizhong1++;
			}
			else{
				zuizhong1--;
			}
		}
		cs++;
	}
//	for(int i=0;i<hs;i++){
//		for(int j=0;j<ls;j++){
//			cout<<wkx[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	cout<<endl;
    cout<<zuizhong1+1<<" "<<zuizhong2+1;                 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
