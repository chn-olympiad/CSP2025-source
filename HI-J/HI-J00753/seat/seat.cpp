#include<bits/stdc++.h>
using namespace std;
bool comp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int num,sum;
    cin>>num>>sum;
    int ai[10005];
    int noi=num*sum;
    for(int i=1;i<=noi;i++){
    	cin>>ai[i];
	} 
	int Rk=ai[1];
	sort(ai+1,ai+1+noi,comp);
	int some[20][20];
	int ans=1;
	bool op=0;
	for(int i=1;i<=sum;i++){
		if(op==0){
			for(int j=1;j<=num;j++){
			    some[j][i]=ai[ans];
			    ans++;
		    }
		    op=1;
		}
		else if(op==1){
			for(int j=num;j>=1;j--){
				some[j][i]=ai[ans];
			    ans++;
			}
			op=0;
		}
	}
	for(int i=1;i<=num;i++){
		for(int j=1;j<=sum;j++){
		    if(some[i][j]==Rk){
		    	cout<<j<<" "<<i;
		    	return 0;
			}	
		}
	}
	return 0;
}

