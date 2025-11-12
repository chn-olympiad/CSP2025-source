#include <bits/stdc++.h>
using namespace std;
int n0,n1,n2,n3,n4,n5,n6,n7,n8,n9,;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    string s;
    cin >> s;
    int y = 0;
    y = s.size();
    for(int i = 0;i < y;i++)
    {
        if(s[i] == '0' || s[i] == '1'|| s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9')
        {
		    if(s[i] == '9')
		    {
			    n9++;
			}
			else
			{
			    if(s[i] == '8')
			    {
				    n8++;
				}
				else
			    {    
			        if(s[i] == '7')
			        {
				        n7++;	
				    }
				    else
			        {
			            if(s[i] == '6')
			            {
				            n6++;
				        }
				        else
			            {
			                if(s[i] == '5')
			                {
				                n5++;
				            }
				            else
			                {
			                    if(s[i] == '4')
			                    {
				                    n4++;	
				                }
				                else
				                {
									if(s[i] == '3')
			                        {
				                        n3++;
				                    }
				                    else
				                    {
										if(s[i] == '2')
			                            {
				                            n2++;
				                        }
				                        else
				                        {
											if(s[i] == '1')
			                                {
				                                n1++;
				                            }
				                            else
				                            {
												if(s[i] == '0')
												{
												    n0++;
											    }   
											}
										}
									}
								}
			                }
			            }
			         }
			     }
			 }
		}
    }
    for(int i= 0;i < n9;i++)
    {
		cout << "9";
	}
	for(int i= 0;i < n8;i++)
    {
		cout << "8";
	}
	for(int i= 0;i < n7;i++)
    {
		cout << "7";
	}
	for(int i= 0;i < n6;i++)
    {
		cout << "6";
	}
	for(int i= 0;i < n5;i++)
    {
		cout << "5";
	}
	for(int i= 0;i < n4;i++)
    {
		cout << "4";
	}
	for(int i= 0;i < n3;i++)
    {
		cout << "3";
	}
	for(int i= 0;i < n2;i++)
    {
		cout << "2";
	}
	for(int i= 0;i < n1;i++)
    {
		cout << "1";
	}
	for(int i= 0;i < n0;i++)
    {
		cout << "0";
	}
}
