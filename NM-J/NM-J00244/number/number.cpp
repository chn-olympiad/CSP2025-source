#include<bits/stdc++.h>
using namespace std;
string lihaoyu1;
int lihaiyu2[15];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>lihaoyu1;
	for(int i=0; i<lihaoyu1.size(); i++)
		if(lihaoyu1[i]-'0'>=0&&lihaoyu1[i]-'0'<=9)lihaiyu2[lihaoyu1[i]-'0']++;
	for(int i=9; i>=0; i--)if(lihaiyu2[i]!=0)for(int j=1; j<=lihaiyu2[i]; j++)cout<<i;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
