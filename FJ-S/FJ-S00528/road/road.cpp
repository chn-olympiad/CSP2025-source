#include<bits/stdc++.h>
using namespace std;
int main()
{
	//太难了我不会
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k,sum=0,min1 = INT_MAX,min2 = INT_MAX;
	cin>>n>>m>>k;
	long long m1[m+10],k1[k+10];
	for(int i=0;i<m*3;i++){
		cin>>m1[i];
		if((i+1) % 3 == 0)
			if(m1[i] <= min1 || m1[i] <= min2){
				if(m1[i] < min1) min1=m1[i];
				else if(m1[i]< min2) min2=m1[i];
			}
	}
	for(int i=0;i<5*k;i++)
		cin>>k1[i];
	cout<<min1+min2;
	return 0;
}
