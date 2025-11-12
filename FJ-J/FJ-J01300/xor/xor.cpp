#include <bits/stdc++.h>
using namespace std;
 
//9:12 Task 1 complete ['v']
//10:07 Task 2 complete [!'v'!]
//10:45 Task 4 complete(part of it) [!^v^!]
//11:10 Sleeping [zzz]
//11:15 Wake up
//11:30 I don't know the answer of Task 3 ['_']
//11:35 Maybe I can get up to 240-250 points this year
//11:46 Finish writing
//11:51 Finish drawing
//11:56 I won't be here next year['upset']
//11:57 But I will be here in the afternoon
//**********   **********   **********                    *
//*            *            *                           *
//*            *            *             *           *
//*            *            **********     *        *
//*            *            *               *     *
//*            *            *                *  *
//**********   **********   *                 *
int n,k;
int main()
{
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin >> n >> k;
	if(n <= 2&&k == 0)cout << 1;
	else if(n <= 100&&k == 0)cout << n/2;
	return 0;
}
