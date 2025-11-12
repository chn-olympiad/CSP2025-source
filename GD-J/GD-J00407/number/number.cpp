#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
string s;
vector <int> num;
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(char c : s)
		if(c >= '0' && c <= '9')
			num.push_back((int) c - '0');
	sort(num.begin(),num.end(),cmp);
	for(int i : num)
		cout << i;
	return 0;
}
/*Hi,I'm LiHua.A middle-school OIer.It's my great pleasure to write this letter to you.
This test not only cosumes my energy but also makes me mad.The 1st problem and the 2nd problem are certainly easy.
But the 3rd problem is so hard that I cannot solve it.And the 4th problem I choose to cheat points.
I could get at least 20 Pts. in the 3rd problem and 36 Pts. in the 4th problem.So I'm not upset to AwayFromOi.
And I've just checked my codes so that I won't get poor grades.*/
