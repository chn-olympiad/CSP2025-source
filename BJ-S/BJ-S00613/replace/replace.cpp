#include <bits/stdc++.h>
#include <ctime>
using namespace std;

char a[53];
int main()
{
	for(int i=1;i<=26;i++)a[i]=i+97-1;
	for(int i=27;i<=52;i++)a[i]=i-26+'A'-1;
	srand(time(0));
	int ju=0,qian=100;
	cout<<"原先你有100个金币。\n";
	while(1)
	{
		ju++;
		LenEr:
		cout<<"第"<<ju<<"局\n"<<endl;
		cout<<"请输入字符串长度\n";
		int len;
		cin>>len;
		if(len>10||len<3)goto LenEr;
		string ans="";
		for(int i=0;i<8880;i++)
		{
			int r1=rand()%52+1;
			int r2=rand()%52+1;
			swap(a[r1],a[r2]);
		}
		for(int i=1;i<=len;i++)ans+=a[i];
		//cout<<ans;
		int guess=0;
		while(1)
		{
			guess++;
			CaiEr:
			cout<<"第"<<guess<<"次猜测，输入猜测串\n";
			string s;
			cin>>s;
			int ssiz=s.size();
			if(s=="0")
			{
				qian-=25;
				cout<<"你放弃了，所以罚款25个金币。答案"<<ans<<endl;
				break;
			}
			if(ssiz!=len)goto CaiEr;
			int dui=0,zimubudui=0,zhong=0,zimubuduiqiezhong=0;
			for(int i=0;i<len;i++)
			{
				for(int j=0;j<len;j++)
				{
					if(i==j && ans[i]==s[j])dui++;
					if(i!=j&&ans[i]==s[j])zhong++;
					if(i==j &&abs(ans[i]-s[j])==32)zimubudui++;
					if(i!=j &&abs(ans[i]-s[j])==32)zimubuduiqiezhong++;
				}
			}
			printf("猜测次数%d，正确%d,字母大小写不对%d,位置错误%d，位置错误且大小写不对%d\n",guess,dui,zimubudui,zhong,zimubuduiqiezhong);
			if(dui==len)
			{
				int guess2=min(15*len,guess);
				int reward=len*(15*len-guess2);
				printf("恭喜你，猜对了。奖励%d个金币。\n",reward);
				qian+=reward;
				break;
			}
		}
		printf("现在%d个金币。\n",qian);
	}
	return 0;
}
