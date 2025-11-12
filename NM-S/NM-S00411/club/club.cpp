#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	int t;
	cin>>t;
	while(t>0){
	int n;
	cin>>n;
	int sum=n/2;
	int arr[3][n];
	for(int i=0;i<n;i++){
	    for(int j=0;j<=2;j++){
	    cin>>arr[i][j];

	    }
	}
	int ans, bns,cns=0;
    int a,b,c;

	    for(int j=1;j<=3*n;j++){
            for(int i=0;i<n;i++){
	   ans+=arr[i][j-1%3];
       if(j-1%3==0){
        a+=1;
       }else if(j-1%3==1){
       b+=1;
       }else{
       c+=1;
       }

       if(a<=sum&&b<=sum&&b<=sum&&c<=sum){
        bns=max(ans,cns);
        cns=ans;

       }

	    }
	    cout<<bns<<endl;
	}
	t--;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
