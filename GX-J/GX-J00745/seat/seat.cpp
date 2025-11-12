#include <bits/stdc++.h>
using namespace std;
int maxof(vector<int>& vec){
	int maxn=vec[0];
	int index=0;
	for(int i=1;i<vec.size();i++){
		if(vec[i]>maxn) {maxn=vec[i];index=i;}
	}
	return index;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> vec(n*m);
    for(int i=0;i<n*m;i++){
        cin>>vec[i];
    }
    int R=vec[0];
    for(int i=0;i<m;i++){
		if(i%2==0){
			for(int j=0;j<n;j++){
				int mi=maxof(vec);
				if(vec[mi]==R){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
				vec[mi]=-1;
			}
		}else{
			for(int j=n-1;j>=0;j--){
				int mi=maxof(vec);
				if(vec[mi]==R){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
				vec[mi]=-1;
			}
		}
	}
}
