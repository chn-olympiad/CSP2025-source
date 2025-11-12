//I'm Luogu UID 1049103 @Airbus_A380
//I'm an OIer from SZSY
//CCF Give Me 1= Please
//I love watching ACI and playing TFS and FGFS
//I WANT TO TAKE PHOTOS OF PLANES
//I'm not sure if ios::sync_with_stdio(false);cin.tie(nullptr); can be used.
//Not using them is a great way.
//I like using LONG LONG but n,m is just 10 and a[i] is just 100 so int is ok to use scanf/printf safely.
//Because n,m is very small so not using LONG LONG maybe good.
//I DON'T WANT TO AFO
#include<bits/stdc++.h>
using namespace std;
//int arr[110][110],dat[110][110];
struct Score{
//	long long rate;
	int rate;
	bool r;
//	bool operator <(const Score& sc) const{
//		return 
//	}
// I am afraid that I am wrong about this so writing a cmp() maybe better
};
bool cmp(Score a,Score b){
	return a.rate>b.rate;
}
Score a[110];
//long long n,m;
//long long s[110][110];
int n,m;
//long long tot;
int tot;
int s[110][110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	tot=n*m;
	for(long long i=1;i<=tot;i++){
		cin>>a[i].rate;
		if(i==1)a[i].r=true;// a[1] for little r
	}
	sort(a+1,a+tot+1,cmp);
	//simulate
	long long r=1,c=0;//begins at Row 1 Column 0
	//c%2==1 -> GO DOWN
	//c%2==0 -> GO UP
	long long cnt=0;
	while(true){
		cnt++;
		if(r<n&&c%2==1){
			r++;
		}else if(r>1&&c%2==0){
			r--;
		}else{
			c++;//cpp
		}
		//find s[r][c]
		if(cnt>tot){
			break;
		}
		if(a[cnt].r==true){
			break;
		}
	}
	//REMEMBER TO OUTPUT COLUMN FIRST 
	cout<<c<<' '<<r<<endl;
	return 0;
}
