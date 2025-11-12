#include<bits/stdc++.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main(){
	srand(time(0));
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=q;i++)
		cout<<rand()%n<<endl;
	return 0;
}
