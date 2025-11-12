#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int first;
	int second;
	int third;
	int num;
}a[N];
bool cmp(node x,node y){
	return x.num<y.num;
}
int sum;
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int one=0,two=0,three=0,x=0,y=0,z=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].first>>a[i].second>>a[i].third;
			a[i].num=a[i].first+a[i].second+a[i].third;
		}
		
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].first>=a[i].second && a[i].first>=a[i].third){
				if(x==n/2){
					if(max(a[i].second,a[i].third)==a[i].second && two<n/2){
						y++;
						two+=a[i].second;
					}
					else if(three<n/2){
						z++;
						three+=a[i].third;
					}
					continue;
				}
				else{
					one+=a[i].first;
					x++;
				}
			}
			else if(a[i].first<=a[i].second && a[i].second>=a[i].third){
				if(x==n/2){
					if(max(a[i].first,a[i].third)==a[i].first && x<n/2){
						x++;
						one+=a[i].first;
					}
					else if(three<n/2){
						z++;
						three+=a[i].third;
					}
					continue;
				}
				else{
					one+=a[i].second;
					y++;
				}
			}
			else if(a[i].first<=a[i].third && a[i].second<=a[i].third){
				if(x==n/2){
					if(max(a[i].first,a[i].second)==a[i].first && x<n/2){
						x++;
						one+=a[i].first;
					}
					else if(two<n/2){
						y++;
						two+=a[i].second;
					}
					continue;
				}
				else{
					one+=a[i].third;
					z++;
				}
			}
		}
		cout<<one+two+three<<endl;
	}
	return 0;
}

