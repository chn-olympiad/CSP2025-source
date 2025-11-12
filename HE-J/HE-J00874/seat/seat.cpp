#include <bits/stdc++.h>
using namespace std;


int n, m, all;
int slist[15][15], in_list[200];
int R;
int lie = 1, hang = 1;
bool iup = false;


bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	all = n * m;
	for (int i = 1; i <= all; i++)
	{
		cin >> in_list[i];
	}
	R = in_list[1];
	sort(in_list + 1, in_list + all + 1, cmp);
	//cout << "-------1-------" << endl << endl << endl;
	for (int i = 1; i <= all; i++)
	{
		//cout << "before if:" << endl << "lie:" << lie << "    hang:" << hang << endl << "now in_list value:" << in_list[i] << endl << "now slist value:" << slist[lie][hang] << endl;
		slist[lie][hang] = in_list[i];
		//cout << "can '='." << endl << "after if:" << endl;
		if (slist[lie][hang] == R)
		{
			cout << lie << ' ' << hang;
			break;
		}
		if (hang == n && (!iup))
		{
			lie++;
			iup = true;
		}
		else if (hang == 1 && iup)
		{
			lie++;
			iup = false;
		}
		else
		{
			if (!iup)
				hang++;
   			else
				hang--;
		}
		//slist[lie][hang] = in_list[i];
		//cout << "lie:" << lie << "    hang:" << hang << endl << "now in_list value:" << in_list[i] << endl << "now slist value:" << slist[lie][hang] << endl << endl;

	}
	return 0;
}
