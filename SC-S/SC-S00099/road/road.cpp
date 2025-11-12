#include<bits/stdc++.h>
using namespace std;
struct rd
{
	int c1,c2;
	int cot;
};
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,ans=0;
    vector<int> spd;
    cin>>n>>m>>k;const int num=m;
    rd road[num+5];
    for(int i=1;i<=m;i++)
    {
    	cin>>road[i].c1>>road[i].c2>>road[i].cot;
    	ans+=road[i].cot
	}
	cout<<ans;
	return 0;
}