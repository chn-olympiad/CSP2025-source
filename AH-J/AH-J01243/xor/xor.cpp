#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main () {
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	int n, k1;
	scanf ("%d %d", &n, &k1);
	for (int i=1; i<=n; i++)
		scanf ("%d", &a[i]);
	int ans = 0;
	if (n <= 2) {
		for (int i=1; i<=n; i++)
			if (a[i] == k1) ans++;
		if ((a[1] ^ a[2]) == k1) ans++;
	}
	if (n == 3) {
		for (int i=1; i<=n; i++)
			if (a[i] == k1) ans++;
		for (int i=1; i<=n-1; i++) {
			for (int j=i+1; j<=n; j++) 
				if ((a[i] ^ a[j]) == k1) ans++; 
		}
		if ((a[1] ^ a[2] ^ a[3]) == k1) ans++;
		return 0;
	}
	if (n == 4) {
		for (int i=1; i<=n; i++)
			if (a[i] == k1) ans++;
		for (int i=1; i<=n-1; i++) {
			for (int j=i+1; j<=n; j++) 
				if ((a[i] ^ a[j]) == k1) ans++; 
		}
		for (int i=1; i<=n-2; i++) 
			for (int j=i+1; j<=n-1; j++) 
				for (int k=j+1; k<=n; k++) 
					if ((a[i] ^ a[j] ^ a[k]) == k1) ans++;
		if ((a[1] ^ a[2] ^ a[3] ^ a[4]) == k1) ans++;
	}
	if (n == 5) {
		for (int i=1; i<=n; i++)
			if (a[i] == k1) ans++;
		for (int i=1; i<=n-1; i++) {
			for (int j=i+1; j<=n; j++) 
				if ((a[i] ^ a[j]) == k1) ans++; 
		}
		for (int i=1; i<=n-2; i++) 
			for (int j=i+1; j<=n-1; j++) 
				for (int k=j+1; k<=n; k++) 
					if ((a[i] ^ a[j] ^ a[k]) == k1) ans++;
		for (int i=1; i<=n-3; i++) 
			for (int j=i+1; j<=n-2; j++) 
				for (int k=j+1; k<=n-1; k++) 
					for (int l=k+1; l<=n; l++) 
						if ((a[i] ^ a[j] ^ a[k] ^ a[l]) == k1) ans++;
		if ((a[1] ^ a[2] ^ a[3] ^ a[4] ^ a[5]) == k1) ans++;
	}
	if (n == 6) {
		for (int i=1; i<=n; i++)
			if (a[i] == k1) ans++;
		for (int i=1; i<=n-1; i++) {
			for (int j=i+1; j<=n; j++) 
				if ((a[i] ^ a[j]) == k1) ans++; 
		}
		for (int i=1; i<=n-2; i++) 
			for (int j=i+1; j<=n-1; j++) 
				for (int k=j+1; k<=n; k++) 
					if ((a[i] ^ a[j] ^ a[k]) == k1) ans++;
		for (int i=1; i<=n-3; i++) 
			for (int j=i+1; j<=n-2; j++) 
				for (int k=j+1; k<=n-1; k++) 
					for (int l=k+1; l<=n; l++) 
						if ((a[i] ^ a[j] ^ a[k] ^ a[l]) == k1) ans++;
		for (int i=1; i<=n-4; i++) 
			for (int j=i+1; j<=n-3; j++) 
				for (int k=j+1; k<=n-2; k++) 
					for (int l=k+1; l<=n-1; l++) 
						for (int z=l+1; z<=n; z++)
							if ((a[i] ^ a[j] ^ a[k] ^ a[l] ^ a[z]) == k1) ans++;
		if ((a[1] ^ a[2] ^ a[3] ^ a[4] ^ a[5] ^ a[6]) == k1) ans++;
	}
	printf ("%d\n", ans);
	return 0;
}
