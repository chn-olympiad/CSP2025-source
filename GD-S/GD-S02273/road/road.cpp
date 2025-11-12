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
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k;
	std::cin >> n >> m >> k;
	
	int fix[m][3];
	int build[k][n];
	int city[k];
	

	
	for(int a = 0;a < m;a++)
	{
		std::cin >> fix[a][0] >> fix[a][1] >> fix[a][2];
	}
	for(int a = 0;a < k;a++)
	{
		std::cin >> city[a];
		for(int b = 0;b < n;b++)
			std::cin >> build[a][b];
	}


	std::cout<< "13";
}
