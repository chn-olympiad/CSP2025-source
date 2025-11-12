#include<bits/stdc++.h>
using namespace std;
int n,t,sum1,sum2,sum3;
const int N=1e5+10;
int a[N],b[N],c[N];
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>t>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		sum1+=a[i];
		ans1+=a[i]/2;
		sum2+=b[i];
		ans2+=b[i]/2;
		sum3+=c[i];
		ans3+=c[i]/2;
		if(sum1>=ans1||sum2>=ans2||sum3>=ans3);
		break;
		else
		cout<<sum1+sum2+sum3;
    }

	return 0;
}
