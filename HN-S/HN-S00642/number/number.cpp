#include <iostream>
#include <stdio.h>

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	
	std::string input;
	std::cin>>input;
	
	unsigned digit_counter[10] = {};
	
	for(auto ch : input)
	{
		if(std::isdigit(ch))
		{
			digit_counter[ch - '0']++;
		}
	}
	
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<digit_counter[i];j++)
		{
			std::cout<<i;
		}
	}
	
	return 0;
}
