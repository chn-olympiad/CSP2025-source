#include<iostream>
#include<algorithm>
using namespace std;

int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int t,n;
	int a[100010][4],a1[100010],a2[100010],a3[100010];
//	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1];
			cin>>a[i][2];
			cin>>a[i][3];
			a1[i]=a[i][1];
			a2[i]=a[i][2];
			a3[i]=a[i][3];
		}
		int f[100100][4];
	//	sort(a1.begin(),a2.end());
	//	sort(a2.begin(),a2.end());
	//	sort(a3.begin(),a3.end());






	}
	int ap[99]={0,12,2,41,0,6,24,10};
	sort(ap[0],ap[7]);
	for(int i=0;i<8;i++){
		cout<<ap[i];
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

