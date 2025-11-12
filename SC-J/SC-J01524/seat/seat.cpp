#include<bits/stdc++.h>
using namespace std;

int seat[10+10][10+10];
int n,m,people,a1;
int a[100+10];
bool a_HasBeenUsed[100+10];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m; people=n*m;
	for (int i=1;i<=people;i++){
		cin>>a[i];
	}
	a1 = a[1];
	sort(a+1,a+people+1);
	int research=people+1;
	for (int i=1;i<=m;i++){
		if (i%2!=0){
			for (int j=1;j<=n;j++){
				research--;
				if (a[research]==a1){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for (int j=n;j>=1;j--){
				research--;
				if (a[research]==a1){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}

/*
Fail Mountain
17:
cout<<"R\'s Score is "<<a1<<endl;

19:
cout<<"\nNow Score Order List:"<<endl;
for (int i=1;i<=people;i++){
cout<<i<<" "<<a[i]<<"; ";
}
cout<<endl;

23,31:
printf("Message from XXX: research is %d, now i = %d, j = %d, a[research] is %d\n",research,i,j,a[research]);
*/
