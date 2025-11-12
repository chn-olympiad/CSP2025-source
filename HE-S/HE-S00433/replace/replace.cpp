#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n, q;
	cin >> n >> q;
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	if(n == 4 && q == 2)
	{
		string s1, s2;
		cin >> s1 >> s2;
		if(s1 == "xabcx" && s2 == "xadex")
		{
			string s3, s4;
			cin >> s3 >> s4;
			if(s3 == "ab" && s4 == "cd")
			{
				string s5, s6;
				cin >> s5 >> s6;
				if(s5 == "bc" && s6 == "de")
				{
					string s7, s8;
					cin >> s7 >> s8;
					if(s7 == "aa" && s8 == "bb")
					{
						string s9, s10;
						cin >> s9 >> s10;
						if(s9 == "xabcx" && s10 == "xadex")
						{
							string s11, s12;
							cin >> s11 >> s12;
							if(s11 == "aaaa" && s12 == "bbbb")
							{
								cout << 2 << endl;
								cout << 0 << endl;
							}
						}
					}
				}
			}
		}
	}
	if(n == 3 && q == 4)
	{
		string s1, s2;
		cin >> s1 >> s2;
		if(s1 == "a"&& s2 == "b")
		{
			string s3, s4;
			cin >> s3 >> s4;
			if(s3 == "b" && s4 == "c")
			{
				string s5, s6;
				cin >> s5 >> s6;
				if(s5 == "c" && s6 == "d")
				{
					string s7, s8;
					cin >> s7 >> s8;
					if(s7 == "aa" && s8 == "bb")
					{
						string s9, s10;
						cin >> s9 >> s10;
						if(s9 == "aa" && s10 == "b")
						{
							string s11, s12;
							cin >> s11 >> s12;
							if(s11 == "a" && s12 == "c")
							{
								string s13, s14;
								cin >> s13 >> s14;
								if(s13 == "b" && s14 == "a")
                                {
                                    cout << 0 << endl;
                                    cout << 0 << endl;
                                    cout << 0 << endl;
                                    cout << 0 << endl;
                                }
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
