#include<bits/stdc++.h>
using namespace std;
int esyhsm[100005][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int num=0;
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>esyhsm[j][1]>>esyhsm[j][2]>>esyhsm[j][3];
			num+=max(esyhsm[j][1],max(esyhsm[j][2],esyhsm[j][3]));
		}
		cout<<num<<endl;
		num=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
