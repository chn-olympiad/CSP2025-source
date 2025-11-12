#include <bits/stdc++.h>
using namespace std;
int t;
const int N = 1e5 + 100;
struct node
{
	int am1, am2, am3;
};
bool cmp1 (node x, node y)
{
	return x.am1 > y.am1;
}
bool cmp2 (node x, node y)
{
	return x.am2 > y.am2;
}
bool cmp3 (node x, node y)
{
	return x.am3 > y.am3;
}
void solve ()
{
	int n, bmr[3] = {0}, cnt1 = 0, cnt2 = 0, cnt3 = 0;
	node a[N];
	scanf ("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i].am1 >> a[i].am2 >> a[i].am3;
	}
	sort (a, a + n, cmp1);
	for (int i = 0; i < n; ++i){
		if (a[i].am1 >= a[i].am2 && a[i].am1 >= a[i].am3){
			if (bmr[0] < (n / 2)){
				cnt1 += a[i].am1;bmr[0]++;
			}else{
				if (a[i].am2 >= a[i].am3){
					if (bmr[1] < (n / 2)){
						bmr[1]++;cnt1 += a[i].am2;
					}else	bmr[2]++;cnt1 += a[i].am3;
				}else	bmr[2]++;cnt1 += a[i].am3;
			}
		}else if (a[i].am2 >= a[i].am1 && a[i].am2 >= a[i].am3){
			if (bmr[1] < (n / 2)){
				cnt1 += a[i].am2;bmr[1]++;
			}else{
				if (a[i].am3 >= a[i].am1){
					if (bmr[2] < (n / 2)){
						bmr[2]++;cnt1 += a[i].am3;
					}else{
						bmr[0]++;cnt1 += a[i].am1;
					}
				}else{
					bmr[0]++;cnt1 += a[i].am1;
				}
			}
		}else{
			if (bmr[2] < (n / 2))
			{
				cnt1 += a[i].am3;bmr[2]++;
			}else{
				if (a[i].am1 >= a[i].am2)
				{
					if (bmr[0] < (n / 2))
					{
						bmr[0]++;cnt1 += a[i].am1;
					}else	bmr[1]++;cnt1 += a[i].am2;
				}else	bmr[1]++;cnt1 += a[i].am2;
			}
		}
	}
	sort (a, a + n, cmp2);
	for (int i = 0; i < n; ++i)	{
		if (a[i].am2 >= a[i].am1 && a[i].am2 >= a[i].am3){
			if (bmr[1] < (n / 2)){
				cnt2 += a[i].am2;bmr[1]++;
			}else{
				if (a[i].am3 >= a[i].am1)
				{
					if (bmr[2] < (n / 2))
					{
						bmr[2]++;cnt2 += a[i].am3;
					}else	bmr[0]++;cnt2 += a[i].am1;
					
				}else	bmr[0]++;cnt2 += a[i].am1;
			}
		}else if (a[i].am3 >= a[i].am1 && a[i].am3 >= a[i].am2){
			if (bmr[2] < (n / 2)){
				cnt2 += a[i].am3;bmr[2]++;
			}else{
				if (a[i].am2 >= a[i].am1){
					if (bmr[1] < (n / 2)){
						bmr[1]++;cnt2 += a[i].am2;
					}else	bmr[0]++;cnt2 += a[i].am1;
				}else		bmr[0]++;cnt2 += a[i].am1;
			}
		}else{
			if (bmr[0] < (n / 2)){
				cnt2 += a[i].am1;bmr[0]++;
			}else{
				if (a[i].am3 >= a[i].am2){
					if (bmr[2] < (n / 2))	bmr[2]++;cnt2 += a[i].am3;
					if (bmr[1] < (n / 2))	bmr[1]++;cnt2 += a[i].am2;
				}else	bmr[1]++;cnt2 += a[i].am2;
			}
		}
	}
	sort (a, a + n, cmp3);
	for (int i = 0; i < n; ++i){
		if (a[i].am3 >= a[i].am1 && a[i].am3 >= a[i].am2){
			if (bmr[2] < (n / 2)){
				cnt2 += a[i].am3;bmr[2]++;
			}else{
				if (a[i].am2 >= a[i].am1){
					if (bmr[1] < (n / 2))	bmr[1]++;cnt3 += a[i].am2;
					if (bmr[0] < (n / 2))	bmr[0]++;cnt3 += a[i].am1;
				}else	bmr[0]++;cnt3 += a[i].am1;
			}
		}else if (a[i].am1 >= a[i].am2 && a[i].am1 >= a[i].am3){
			if (bmr[0] < (n / 2)){
				cnt3 += a[i].am1;bmr[0]++;
			}else{
				if (a[i].am3 >= a[i].am2)
				{
					if (bmr[2] < (n / 2))	bmr[2]++;cnt3 += a[i].am3;
					if (bmr[1] < (n / 2))	bmr[1]++;cnt3 += a[i].am2;
				}else bmr[1]++;cnt3 += a[i].am2;
				
			}
		}else{
			if (bmr[1] < (n / 2)){
				cnt3 += a[i].am2;bmr[1]++;
			}else{
				if (a[i].am1 >= a[i].am3){
					if (bmr[0] < (n / 2))	bmr[0]++;cnt3 += a[i].am1;
					if (bmr[2] < (n / 2)) bmr[2]++;cnt3 += a[i].am3;
				}else	bmr[2]++;cnt3 += a[i].am3;
			}
		}
	}
	cout << max (cnt1, max (cnt2, cnt3));
	return ;
}
int main (){
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	
	cin >> t;
	while (t--){
		solve ();
	}
	
	fclose (stdin);
	fclose (stdout);	
	return 0;
} 
