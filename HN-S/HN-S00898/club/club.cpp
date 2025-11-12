#include<bits/stdc++.h>
using namespace std;

int t;

struct club_m{
	int first,second,third;
	int m=max(first,max(second,third));
};

bool cmp(club_m c1,club_m c2){
	return (c1.m>c2.m?false:true);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n,one=0,two=0,three=0,one_m=0,two_m=0,three_m=0;
		cin>>n;
		club_m a[n];
		for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second>>a[i].third;
		sort(a,a+n,cmp);  
		for(int i=0;i<n;i++){
			if(a[i].m==a[i].first&&one+1<=(n/2)){
				one++;
				one_m+=a[i].m;
			}else if(a[i].m==a[i].second&&two+1<=(n/2)){
				two++;
				two_m+=a[i].m;
			}else if(a[i].m==a[i].third&&three+1<=(n/2)){
				three++;
				three_m+=a[i].m;
			}else{
				continue;
			}
		}
		cout<<(one_m+two_m+three_m) <<endl;
	}
	return 0;
}
