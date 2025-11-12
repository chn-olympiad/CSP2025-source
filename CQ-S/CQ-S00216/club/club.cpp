#include<iostream>
#include<iomanip>
#include<algorithm> 
#include<vector>
#include<cmath>
using namespace std;
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	

	int t;
	cin >> t;
	while(t--)
	{
		int n,num=0;
		cin >> n;
		vector<vector<int>> arr(3,vector<int>(n,0));
		for(int i=0;i<n;i++){
			cin >> arr[0][i] >> arr[1][i] >> arr[2][i];
		}
		if(n == 2)
		{
			num+=max(arr[0][0],max(arr[1][0],arr[2][0]))+max(arr[1][1],max(arr[0][1],arr[2][1]));
		}else {
			sort(arr[0].begin(),arr[0].end(),cmp);
			for(int i=0;i<n/2;i++) {
				num+=arr[0][i];
			}
		}
		cout<<num<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
