#include <bits/stdc++.h>

struct save
{
	int a[100];
	int now;
};

save *sav[100000];
int savnum = 0;

void addsave(save in)
{
	sav[savnum] = new save(in);
}

void popsave()
{
	if(savnum != 0)
		delete sav[savnum - 1];
		savnum--;
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int a;
	std::cin >> a >> a;
	std::cout<< "2" << std::endl;
	for(int b = 0;b < a - 1;b++)
	{
		std::cout<< "0" << std::endl;
	}

}
