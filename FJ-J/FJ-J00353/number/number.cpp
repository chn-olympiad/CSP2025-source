#include<bits/stdc++.h>
using namespace std;
int nums[1000020];
string output;
long long output_max_idx=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
//	int n=s.size();
	int num_count=0;
	for(int i=0;s[i];i++)
	{
		if(s[i]<='9' and s[i]>-'0')
		{
			nums[num_count]=s[i]-'0';
			num_count++;
//			cout<<num_count<<endl;
		}
	}
//	num_count--;
	//排序后从高到低依次拼接数字
	sort(nums,nums+num_count);//排序后列表：从低到高 
	for(int i=num_count-1;i>=0;i--)
	{
		output+='0'+nums[i];
		output_max_idx++;
	}
	cout<<output;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
