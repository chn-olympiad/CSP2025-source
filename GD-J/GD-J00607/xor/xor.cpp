#include<bits/stdc++.h>
using namespace std;

struct Segment{
	int start,end;
};

vector<Segment>AC;

bool cmp(Segment a,Segment b){
	if(a.end < b.end)return 1;
	if(a.end > b.end)return 0;
	return a.start > b.start;
}

//O(n^2)的方法，燃尽了
 
int Prexor[500010];
int L[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int v;cin>>v;
		L[i] = v;
		Prexor[i] = Prexor[i-1] ^ v;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((Prexor[j] ^ Prexor[i-1]) == k)
				AC.push_back((Segment){i,j});	
		}
	}
	
	sort(AC.begin(),AC.end(),cmp);
	int cnt = 0,end = 0;
	for(int i=0;i<(int)AC.size();i++){
		Segment c = AC[i];
		if(end < c.start)
		{
			cnt++;
			end = c.end;
		}
	}
	cout<<cnt;
	return 0;
}
//666
//Code by rainy_mid 
