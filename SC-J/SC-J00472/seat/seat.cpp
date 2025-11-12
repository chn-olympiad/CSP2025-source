#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long a,b,cnt=0;
	cin>>a>>b;
	vector<long long>list(a*b);
	for(long long i=1;i<=a*b;i++){
		cin>>list[i];
	}
	long long r=list[1],hang=1,lie=1;
	sort(list.begin(),list.end()+1);
	for(long long i=a*b;i>=1;i--){
		if(list[i]==r){
			if(hang%2==1){
				cout<<hang<<" "<<lie;
				break;
			}
			else{
				cout<<hang<<" "<<b-cnt/4%4;
				break;
			}
		}
		lie+=1;
		cnt+=1;
		if(lie>a){
			lie=1;
			hang++;
		} 
	}
	return 0;
} 