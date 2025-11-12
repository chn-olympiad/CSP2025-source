#include<bits/stdc++.h>
using namespace std;
int b[500010];
int xors[500010];
vector<pair<int,int>>v;
bool cmp(pair<int,int>a,pair<int,int>b){
	return a.second<b.second;
}
int main(){
	srand(time(0));
	int ans=0;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin>>n;
	int t1;//=rand()%n;
	cin>>t1;
	//cout<<t1<<endl;
	int allxor=0;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	//b[i]=rand()%n;
	//cout<<b[i]<<' ';
		allxor^=b[i];
		xors[i]=allxor;
	}
	int t=0;
	int t11=1;
	for(int i=1;i<=n;i++){
		t=xors[i];
		t^=xors[t11-1];
		if(b[i]==t1){
			ans++;
			t11=i;
			continue;
		}
		for(int j=t11+1;j<=i;j++){
			t^=b[j-1];
			//printf("%2d ",t);
			if(t==t1){
	//			printf("[%d,%d]\n",j,i);
				ans++;
				t11=i;
				break;
			}
		}
	}
	cout<<ans<<endl;
	/*
	int ans1=0;
	for(int i=1;i<=n;i++){
		int t11=0;
		for(int j=i;j<=n;j++){
			t11^=b[j];
			if(t11==t1){
				v.push_back({i,j});
			}
		}
	}
	sort(v.begin(),v.end(),cmp);
	int tt=0;
	for(auto i:v){
		if(i.first>tt){
		cout<<i.first<<' '<<i.second<<endl;
			tt=i.second;
			ans1++;
		}
	}
	cout<<' '<<ans1;
	*/
}
/*
10 5
4 2 4 9  2 2  5  9 0 0 
4 6 2 11 9 11 14 7 7 7
[2,8]=[1,8]^[1,1]=7^4=3!=5
1
5 7=[1,7]^[1,4]=14^11=5
 1
8 4 2
8   2 1
*/
