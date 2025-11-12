#include <iostream>
#include <queue>
using namespace std;
priority_queue<int> str;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    char c = '0';
    while (c!=10) {
        c = getchar();
        if (c>=48 && c<=57) {
            str.push(c-'0');
        }
    }
    while (!str.empty()) {
        cout << str.top();
        str.pop();
    }
    fclose(stdin);
    fclose(stdout);
	return 0;
}
