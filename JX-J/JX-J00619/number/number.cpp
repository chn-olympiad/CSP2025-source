#include <bits/stdc++.h>
using namespace std;
int nums[1000010],k;
int main(){
	//easy!
	//i can do it with my feet

	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//freopen must be right

	string in;
	cin>>in;
	for(int i=0;i<=(int)in.length();i++)
		if(in[i]>='0'&&in[i]<='9'){
			nums[k]=in[i]-'0';
			k++;
		}

	sort(nums,nums+k);//sort the list
	while(k--)
		cout<<nums[k];//print the list from k to 0

	return 0;
}